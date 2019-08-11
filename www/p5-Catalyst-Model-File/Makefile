# $NetBSD: Makefile,v 1.15 2019/08/11 13:24:31 wiz Exp $

DISTNAME=	Catalyst-Model-File-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Model-File
COMMENT=	File based storage model for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.69000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Component-InstancePerContext-[0-9]*:../../www/p5-Catalyst-Component-InstancePerContext
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Model/File/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
