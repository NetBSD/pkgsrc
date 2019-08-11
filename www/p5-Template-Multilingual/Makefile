# $NetBSD: Makefile,v 1.17 2019/08/11 13:25:00 wiz Exp $

DISTNAME=	Template-Multilingual-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Multilingual
COMMENT=	Subclass of Template Toolkit supporting multilingual templates
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Template/Multilingual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
