# $NetBSD: Makefile,v 1.13 2004/04/27 05:44:23 snj Exp $
#

NAME=			CGI-Lite-2.001
DISTNAME=       	${NAME}-emergencyrelease
PKGNAME=        	p5-${NAME}
SVR4_PKGNAME=		p5cgl
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		bad@NetBSD.org
COMMENT=		Simple perl5 module for writing forms-based CGI programs

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Lite/.packlist

pre-configure:
	${CP} ${FILESDIR}/Makefile.PL ${WRKDIR}/Makefile.PL

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
