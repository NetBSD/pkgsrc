# $NetBSD: Makefile,v 1.5 2006/02/22 20:52:11 wiz Exp $

DISTNAME=	raggle-0.4.4
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.raggle.org/
COMMENT=	Console-based screen(1)-aware RSS reader written in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-ncurses>=0.8:../../devel/ruby-ncurses

NO_BUILD=	yes

REPLACE_RUBY=	raggle extras/feed_dump.rb extras/feed_sizes.rb \
		extras/rss_dir_list.rb extras/rss_grab.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
