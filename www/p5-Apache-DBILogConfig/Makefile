# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:59 jlam Exp $
#

DISTNAME=	Apache-DBILogConfig-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5adc
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache-DBILogConfig/
COMMENT=	Database-independent Apache database logger

DEPENDS+=	p5-Apache-DBI>=0.87:../../databases/p5-Apache-DBI
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=		auto/Apache/DBILogConfig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
