# $NetBSD: Makefile,v 1.5 2002/07/05 07:14:45 tron Exp $
#

DISTNAME=	Apache-DBILogConfig-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adc
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	packages@NetBSD.org
COMMENT=	A database-independent Apache database logger

DEPENDS+=	ap-DBI-[0-9]*:../../www/ap-DBI
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/DBILogConfig/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
