# $NetBSD: Makefile,v 1.1 2002/07/05 06:58:34 tron Exp $
#

DISTNAME=      	TimeDate-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 TimeDate distribution

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/TimeDate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
