# $NetBSD: Makefile,v 1.5 2005/02/23 19:12:43 wiz Exp $

DISTNAME=	MasonX-Request-WithApacheSession-0.30
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mxa
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MasonX/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MasonX-Request-WithApacheSession/
COMMENT=	Perl5 module adding a session to the Mason Request obj

DEPENDS+=	p5-Apache-Session-Wrapper>=0.13:../../www/p5-Apache-Session-Wrapper
DEPENDS+=	p5-HTML-Mason>=1.16:../../www/p5-HTML-Mason

USE_BUILDLINK3=	YES

PLIST_SUBST+=	INSTALLSITELIB=${PERL5_INSTALLSITELIB:S^${LOCALBASE}/^^}
PLIST_SUBST+=	INSTALLSITEMAN3DIR=${PERL5_INSTALLSITEMAN3DIR:S^${LOCALBASE}/^^}
PERL5_USES_MODULE_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
