# $NetBSD: Makefile,v 1.9 2002/09/25 14:38:49 seb Exp $
#

DISTNAME=       	CGI-Lite-2.0
PKGNAME=        	p5-${DISTNAME}
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
