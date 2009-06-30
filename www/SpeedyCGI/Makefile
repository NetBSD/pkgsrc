# $NetBSD: Makefile,v 1.12 2009/06/30 00:07:23 joerg Exp $

DISTNAME=	CGI-SpeedyCGI-2.22
PKGNAME=	SpeedyCGI-2.22
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://daemoninc.com/SpeedyCGI/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://daemoninc.com/SpeedyCGI/
COMMENT=	Speed up perl scripts by running them persistently

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

BUILDLINK_API_DEPENDS.perl+=	perl>=5.10
PERL5_PACKLIST= 		auto/CGI/SpeedyCGI/.packlist

SUBST_CLASSES+=		run
SUBST_STAGE.run=	post-patch
SUBST_FILES.run=	src/optdefs
SUBST_SED.run+=		-e "s|@@PREFIX@@|${PREFIX}|g"
SUBST_MESSAGE.run=	Fixing hardcoded paths.

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
