# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:31 ryoon Exp $

DISTNAME=	Template-Multilingual-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Multilingual/
COMMENT=	Subclass of Template Toolkit supporting multilingual templates
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Template/Multilingual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
