# $NetBSD: Makefile,v 1.6 2001/04/10 00:44:26 mjl Exp $
#

DISTNAME=       	CGI-Lite-2.0
PKGNAME=        	p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@netbsd.org
COMMENT=		simple perl5 module for writing forms-based CGI programs

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Lite/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKDIR}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
