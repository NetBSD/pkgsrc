# $NetBSD: Makefile,v 1.16 2004/12/20 11:31:13 grant Exp $
#

PKGVER=			0.67
DISTNAME=       	FCGI-${PKGVER}
PKGNAME=        	p5-FCGI-${PKGVER}
SVR4_PKGNAME=		p5fcg
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.fastcgi.com/
COMMENT=		Perl5 library for FastCGI, a fast startup alternative to CGI

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
