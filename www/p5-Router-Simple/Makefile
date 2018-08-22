# $NetBSD: Makefile,v 1.9 2018/08/22 09:47:52 wiz Exp $

DISTNAME=	Router-Simple-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Router/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tokuhirom/p5-router-simple
COMMENT=	Simple HTTP router for web applications
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=	perl:run

DEPENDS+=	p5-Class-Accessor-Lite-[0-9]*:../../devel/p5-Class-Accessor-Lite

PERL5_PACKLIST=	auto/Router/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
