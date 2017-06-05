# $NetBSD: Makefile,v 1.28 2017/06/05 14:25:08 ryoon Exp $
#

DISTNAME=	Apache-DBILogConfig-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
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
