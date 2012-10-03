# $NetBSD: Makefile,v 1.20 2012/10/03 21:59:05 wiz Exp $
#

DISTNAME=	weblint-1.020
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.perl.com/CPAN/authors/id/NEILB/ \
		ftp://ftp.gmd.de/mirrors/CPAN/authors/id/NEILB/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.weblint.org/
COMMENT=	HTML validator and sanity checker

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl:run
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
