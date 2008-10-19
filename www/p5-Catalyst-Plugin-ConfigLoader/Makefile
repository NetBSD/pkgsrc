# $NetBSD: Makefile,v 1.3 2008/10/19 19:19:06 he Exp $

DISTNAME=	Catalyst-Plugin-ConfigLoader-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-ConfigLoader/
COMMENT=	Load Catalyst config from YAML file

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Data-Visitor>=0.02:../../devel/p5-Data-Visitor
DEPENDS+=	p5-Config-Any>=0.08:../../devel/p5-Config-Any

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/ConfigLoader/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
