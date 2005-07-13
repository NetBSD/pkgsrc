# $NetBSD: Makefile,v 1.18 2005/07/13 18:01:46 jlam Exp $
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

PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
