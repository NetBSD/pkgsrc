# $NetBSD: Makefile,v 1.2 2005/04/11 21:47:59 tv Exp $

DISTNAME=	HTTP-Cache-Transparent-0.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Cache-Transparent/
COMMENT=	Cache the result of http get-requests persistently

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTTP/Cache/Transparent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
