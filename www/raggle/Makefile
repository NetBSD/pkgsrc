# $NetBSD: Makefile,v 1.12 2012/10/28 06:31:02 asau Exp $

DISTNAME=	raggle-0.4.4
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.raggle.org/
COMMENT=	Console-based screen(1)-aware RSS reader written in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-ncurses>=0.8:../../devel/ruby-ncurses

CONFLICTS+=	ruby[1-9][0-9]-raggle-[0-9]* raggle-[0-9]*

NO_BUILD=	yes

REPLACE_RUBY=	raggle extras/feed_dump.rb extras/feed_sizes.rb \
		extras/rss_dir_list.rb extras/rss_grab.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
