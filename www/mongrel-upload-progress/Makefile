# $NetBSD: Makefile,v 1.5 2017/07/30 22:32:25 wiz Exp $

DISTNAME=	mongrel_upload_progress-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fauna/mongrel
COMMENT=	Mongrel plugin to track file upload status

DEPENDS+=	${RUBY_PKGPREFIX}-mongrel>=0.3.13.3:../../www/mongrel

CONFLICTS+=	ruby[1-9][0-9]-mongrel-upload-progress-[0-9]* \
		mongrel-upload-progress-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
