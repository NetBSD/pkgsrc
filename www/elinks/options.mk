# $NetBSD: options.mk,v 1.21 2025/02/07 16:18:14 pho Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.elinks
PKG_SUPPORTED_OPTIONS=		cgi elinks-exmode gssapi nls samba terminfo x11
PKG_OPTIONS_OPTIONAL_GROUPS=	js tls
PKG_OPTIONS_GROUP.js=		mujs quickjs spidermonkey
PKG_OPTIONS_GROUP.tls=		gnutls openssl
# spidermonkey (mozjs) runs faster than quickjs, but it's less portable
# because it uses Rust. The default should be a portable interpreter.
PKG_SUGGESTED_OPTIONS=		nls terminfo quickjs gnutls

.include "../../mk/bsd.options.mk"

###
### CGI support
###
.if !empty(PKG_OPTIONS:Mcgi)
# This doesn't require any external libraries but since it can cause
# security issues it should be toggleable.
MESON_ARGS+=	-Dcgi=true
.endif

###
### Enable ex-mode, turning the UI into something vim-like
###
.if !empty(PKG_OPTIONS:Melinks-exmode)
# The upstream says this is an incomplete feature, which is why it's a
# build-time option but not a run-time one.
MESON_ARGS+=	-Dexmode=true
.endif

###
### GSSAPI support
###
.if !empty(PKG_OPTIONS:Mgssapi)
MESON_ARGS+=	-Dgssapi=true
.  include "../../mk/krb5.buildlink3.mk"
.endif

###
### Native language support
###
PLIST_VARS+=	nls
.if !empty(PKG_OPTIONS:Mnls)
MESON_ARGS+=	-Dnls=true
USE_TOOLS+=	msgfmt xgettext
PLIST.nls=	yes
.  include "../../devel/gettext-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Dnls=false
.endif

###
### Samba protocol support
###
.if !empty(PKG_OPTIONS:Msamba)
MESON_ARGS+=	-Dsmb=true
.  include "../../net/samba4/buildlink3.mk"
.endif

###
### Use terminfo for detecting terminal capabilities
###
.if !empty(PKG_OPTIONS:Mterminfo)
MESON_ARGS+=	-Dterminfo=true
USE_CURSES=	wide
.  include "../../devel/ncurses/buildlink3.mk"
.endif

###
### Use the X Window System
###
.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=	-Dx=true
.  include "../../x11/libX11/buildlink3.mk"
.endif

###
### ECMAScript support
###
.if !empty(PKG_OPTIONS:Mmujs)
MESON_ARGS+=	-Dmujs=true
.  include "../../lang/mujs/buildlink3.mk"
.  include "../../databases/sqlite3/buildlink3.mk"

.elif !empty(PKG_OPTIONS:Mquickjs)
MESON_ARGS+=	-Dquickjs=true
.  include "../../lang/quickjs/buildlink3.mk"
.  include "../../databases/sqlite3/buildlink3.mk"

.elif !empty(PKG_OPTIONS:Mspidermonkey)
MESON_ARGS+=	-Dsm-scripting=true -Dspidermonkey=true
.  include "../../lang/mozjs128/buildlink3.mk"
.  include "../../databases/sqlite3/buildlink3.mk"
.endif

###
### TLS support
###
.if !empty(PKG_OPTIONS:Mgnutls)
MESON_ARGS+=	-Dgnutls=true -Dopenssl=false
.  include "../../security/gnutls/buildlink3.mk"
.  include "../../security/libgcrypt/buildlink3.mk"

.elif !empty(PKG_OPTIONS:Mopenssl)
MESON_ARGS+=	-Dgnutls=false -Dopenssl=true
.  include "../../security/openssl/buildlink3.mk"

.else
MESON_ARGS+=	-Dgnutls=false -Dopenssl=false
.endif
