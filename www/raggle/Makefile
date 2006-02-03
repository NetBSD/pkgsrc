# $NetBSD: Makefile,v 1.3 2006/02/03 04:43:47 taca Exp $

DISTNAME=	raggle-0.4.4
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.raggle.org/
COMMENT=	Console-based screen(1)-aware RSS reader written in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-ncurses>=0.8:../../devel/ruby-ncurses

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=2.4.0:../../textproc/ruby-rexml
.endif

NO_BUILD=	yes

REPLACE_RUBY=	raggle extras/feed_dump.rb extras/feed_sizes.rb \
		extras/rss_dir_list.rb extras/rss_grab.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
