# $NetBSD: Makefile,v 1.10 2002/09/25 14:30:48 seb Exp $
#

PKGVER=			0.58
DISTNAME=       	FCGI-${PKGVER}
PKGNAME=        	p5-FCGI-${PKGVER}
SVR4_PKGNAME=		p5fcg
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/
COMMENT=		perl5 library for FastCGI, a fast startup alternative to CGI

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
