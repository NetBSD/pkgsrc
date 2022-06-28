# $NetBSD: Makefile,v 1.25 2022/06/28 11:37:13 wiz Exp $

DISTNAME=	Catalyst-Action-RenderView-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Action-RenderView
COMMENT=	Catalyst render action target
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.70000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Data-Visitor>=0.24:../../devel/p5-Data-Visitor
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

BUILD_DEPENDS+=	p5-HTTP-Request-AsCGI-[0-9]*:../../www/p5-HTTP-Request-AsCGI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Action/RenderView/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
