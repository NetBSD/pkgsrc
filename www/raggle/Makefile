# $NetBSD: Makefile,v 1.11 2010/09/13 14:12:15 taca Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
