# $NetBSD: Makefile,v 1.3 2004/11/07 18:30:44 kristerw Exp $

DISTNAME=	MasonX-Request-WithApacheSession-0.30
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mxa
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MasonX/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MasonX-Request-WithApacheSession/
COMMENT=	Perl5 module adding a session to the Mason Request obj

DEPENDS+=	p5-Apache-Session-Wrapper>=0.13:../../www/p5-Apache-Session-Wrapper
DEPENDS+=	p5-HTML-Mason>=1.16:../../www/p5-HTML-Mason
BUILD_DEPENDS+=	p5-Module-Build>=0.20:../../devel/p5-Module-Build

USE_BUILDLINK3=	YES

PLIST_SUBST+=	INSTALLSITELIB=${PERL5_INSTALLSITELIB:S^${LOCALBASE}/^^}
PLIST_SUBST+=	INSTALLSITEMAN3DIR=${PERL5_INSTALLSITEMAN3DIR:S^${LOCALBASE}/^^}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
