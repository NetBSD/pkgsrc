# $NetBSD: Makefile,v 1.18 2018/08/22 09:47:27 wiz Exp $

DISTNAME=	Alien-GvaScript-1.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Alien-GvaScript/
COMMENT=	Gva extension to the prototype javascript framework
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Alien/GvaScript/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
