# $NetBSD: Makefile,v 1.9 2003/12/03 22:14:46 kristerw Exp $
#

DISTNAME=	Apache-DBILogConfig-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adc
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Database-independent Apache database logger

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/DBILogConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
