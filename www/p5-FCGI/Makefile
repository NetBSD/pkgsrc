# $NetBSD: Makefile,v 1.7 2001/03/21 16:47:10 mjl Exp $
#

PKGVER=			0.58
DISTNAME=       	FCGI-${PKGVER}
PKGNAME=        	p5-FCGI-${PKGVER}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.fastcgi.com/
COMMENT=		perl5 library for FastCGI, a fast startup alternative to CGI

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/FCGI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
