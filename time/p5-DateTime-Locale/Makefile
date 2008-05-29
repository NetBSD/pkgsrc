# $NetBSD: Makefile,v 1.10 2008/05/29 08:29:06 abs Exp $

DISTNAME=	DateTime-Locale-0.4001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Locale/
COMMENT=	Localization data for p5-DateTime

DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Locale/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
