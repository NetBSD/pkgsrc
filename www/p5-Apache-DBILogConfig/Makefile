# $NetBSD: Makefile,v 1.13 2005/04/11 21:47:55 tv Exp $
#

DISTNAME=	Apache-DBILogConfig-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adc
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-DBILogConfig/
COMMENT=	Database-independent Apache database logger

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/DBILogConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
