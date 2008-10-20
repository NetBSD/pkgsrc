# $NetBSD: Makefile,v 1.1.1.1 2008/10/20 23:40:19 he Exp $

DISTNAME=	Rose-HTMLx-Form-Related-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-HTMLx-Form-Related/
COMMENT=	RHTMLO forms, living together

DEPENDS+=	p5-Data-Dump>=0:../../devel/p5-Data-Dump
DEPENDS+=	p5-Rose-HTML-Objects>=0:../../www/p5-Rose-HTML-Objects
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Autocomplete>=0:../../www/p5-Rose-HTMLx-Form-Field-Autocomplete
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Boolean>=0:../../www/p5-Rose-HTMLx-Form-Field-Boolean
DEPENDS+=	p5-Rose-HTMLx-Form-Field-Serial>=0.002:../../www/p5-Rose-HTMLx-Form-Field-Serial

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Related/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
