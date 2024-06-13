# How to Set Up a Mozilla/Firefox Syncserver

This document tries to summarize how to set up a Mozilla (Firefox)
syncserver.

A syncserver keeps bookmarks, open tabs, passwords, etc. in sync on
different connected devices.

The standard setup consists of an account server (fxa), a token
server, and a syncstorage. The account server is not packaged and for
this document we'll use the Mozilla standard account server. [Mozilla
claims this is safe (they also claim it is safe to use their token
servers and syncstorages).]

This document assumes you have a mariadb-server installed and will
provide the sync service from https://hostname.tld/ using nginx.

## Database

Create a database user (replacing "SECRET_PASSWORD" with your own
password):

> mariadb
CREATE USER "syncstorage_user"@"localhost" IDENTIFIED BY "SECRET_PASSWORD";

Create the databases for the tokenserver and syncstorage:

> mariadb
CREATE DATABASE syncstorage_rs;
CREATE DATABASE tokenserver_rs;
GRANT ALL PRIVILEGES on syncstorage_rs.* to syncstorage_user@localhost;
GRANT ALL PRIVILEGES on tokenserver_rs.* to syncstorage_user@localhost;

After the first start of the program we'll need to add some data into
the tokenserver table, more on that below.

## Syncserver

Provide a config file. The default config file is lacking at least
    tokenserver.run_migrations = true
so here's a full working example:

port=5000
syncstorage.database_url = "mysql://syncstorage_user:SECRET_PASSWORD@127.0.0.1:3306/syncstorage_rs"
# get secret with: head -c 20 /dev/urandom | sha1sum
master_secret = "MASTER_SECRET"
human_logs = 1
tokenserver.enabled = true
tokenserver.node_type = "mysql"
tokenserver.database_url = "mysql://syncstorage_user:SECRET_PASSWORD@127.0.0.1:3306/tokenserver_rs"
# This is a separate password, not sure what it is for
tokenserver.fxa_metrics_hash_secret = "METRICS_SECRET"
tokenserver.fxa_email_domain = "api.accounts.firefox.com"
tokenserver.fxa_oauth_server_url = "https://oauth.accounts.firefox.com/v1"
# needed so that databases (tokenserver_rs.*) are created
tokenserver.run_migrations = true
cors_allowed_origin = "null"
cors_max_age = 86400

Start the syncserver program (which provides both a token server and a syncstorage):

> syncserver --config=/usr/pkg/etc/firefox-syncstorage.toml

and shortly afterwards stop it again, then add some missing information into the database:

(make sure to replace hostname.tld with your proper host name, and don't let it end with a slash)
> mariadb
USE tokenserver_rs;
INSERT IGNORE INTO services (id, service, pattern) VALUES ('1', 'sync-1.5', '{node}/1.5/{uid}');
INSERT INTO nodes (id, service, node, available, current_load, capacity, downed, backoff) VALUES ('1', '1', 'https://hostname.tld', '1', '0', '5', '0', '0');

You can now start the syncserver program again and keep it running.

## nginx

Add a section for the hostname (replacing hostname.tld with your own
again):

    server {
        listen  443 ssl;
        listen       [::]:443 ssl;
        server_name hostname.tld;

        location / {
            proxy_set_header Host $http_host;
            proxy_set_header X-Forwarded-Proto $scheme;
            proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
            proxy_set_header X-Real-IP $remote_addr;
            proxy_redirect off;
            proxy_read_timeout 120;
            proxy_connect_timeout 10;
            proxy_pass http://127.0.0.1:5000/;
        }

    ssl_certificate /path/to/fullchain.pem;
    ssl_certificate_key /path/to/privkey.pem;
}

and restart nginx.

## Firefox configuration

Open "about:config" and set the value of
"identity.sync.tokenserver.url" to
"https://hostname.tld/1.0/sync/1.5". That should be all.

On iOS devices, it's a bit more difficult:
- Open the Firefox settings
- make sure syncing is disconnected
- scroll to the bottom
- tap the "Firefox XXX.Y" Version about 5 times
- scroll up again, where you'll now have "Advanced Sync Settings",
  enter it
- Turn on "Use Custom Sync Token Server"
- Enter "https://hostname.tld/" in the field below
  (do not enter the full path like for Desktop browsers!)
- Turn on sync (open firefox.com/pair in the Desktop version and scan
  the QR Code)
