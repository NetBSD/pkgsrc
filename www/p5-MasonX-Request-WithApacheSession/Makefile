# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 23:35:30 he Exp $

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

USE_BUILDLINK3=	YES
# PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/MasonX/Request/WithApacheSession/.packlist

PLIST_SUBST+=	INSTALLSITELIB=${PERL5_INSTALLSITELIB:S^${LOCALBASE}/^^}
PLIST_SUBST+=	INSTALLSITEMAN3DIR=${PERL5_INSTALLSITEMAN3DIR:S^${LOCALBASE}/^^}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
