# $NetBSD: Makefile,v 1.10 2003/03/02 20:26:04 mjl Exp $
#

NAME=			CGI-Lite-2.001
DISTNAME=       	${NAME}-emergencyrelease
PKGNAME=        	p5-${NAME}
SVR4_PKGNAME=		p5cgl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@netbsd.org
COMMENT=		simple perl5 module for writing forms-based CGI programs

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Lite/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKDIR}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
