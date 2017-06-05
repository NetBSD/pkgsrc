# $NetBSD: Makefile,v 1.21 2017/06/05 14:25:14 ryoon Exp $

DISTNAME=	Catalyst-Plugin-ConfigLoader-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-ConfigLoader/
COMMENT=	Load Catalyst config from YAML file
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.80000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Config-Any>=0.20:../../devel/p5-Config-Any
DEPENDS+=	p5-Data-Visitor>=0.24:../../devel/p5-Data-Visitor
DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/ConfigLoader/.packlist

EXTRACT_USING=	gtar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
