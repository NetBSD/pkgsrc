# $NetBSD: Makefile,v 1.1.1.1 2001/10/01 02:09:46 jlam Exp $

DISTNAME=	Apache-Filter-1.019
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module to alter the output of previous Apache handlers

DEPENDS+=	ap-perl>=1.25:../../www/ap-perl

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Apache/Filter/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
