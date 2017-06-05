# $NetBSD: Makefile,v 1.17 2017/06/05 14:25:30 ryoon Exp $

DISTNAME=	Rose-HTMLx-Form-Related-0.24
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-HTMLx-Form-Related/
COMMENT=	RHTMLO forms, living together
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Rose-HTML-Objects-[0-9]*:../../www/p5-Rose-HTML-Objects
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Autocomplete-[0-9]*:../../www/p5-Rose-HTMLx-Form-Field-Autocomplete
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Boolean-[0-9]*:../../www/p5-Rose-HTMLx-Form-Field-Boolean
DEPENDS+=	p5-Rose-HTMLx-Form-Field-PopUpMenuNumeric-[0-9]*:../../www/p5-Rose-HTMLx-Form-Field-PopUpMenuNumeric
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Serial>=0.002:../../www/p5-Rose-HTMLx-Form-Field-Serial

# For test target
BUILD_DEPENDS+=	p5-Rose-DB-Object-[0-9]*:../../databases/p5-Rose-DB-Object
BUILD_DEPENDS+=	p5-Rose-DBx-Object-MoreHelpers-[0-9]*:../../databases/p5-Rose-DBx-Object-MoreHelpers
BUILD_DEPENDS+=	p5-DBIx-Class>=0.08010:../../databases/p5-DBIx-Class
BUILD_DEPENDS+=	p5-DBIx-Class-RDBOHelpers-[0-9]*:../../databases/p5-DBIx-Class-RDBOHelpers

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Related/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
