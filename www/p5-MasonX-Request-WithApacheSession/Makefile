# $NetBSD: Makefile,v 1.6 2005/02/24 22:38:42 jlam Exp $

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

USE_BUILDLINK3=		yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/MasonX/Request/WithApacheSession/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
