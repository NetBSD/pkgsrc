# $NetBSD: Makefile,v 1.1.1.1 2009/01/19 17:59:05 abs Exp $

DISTNAME=	Catalyst-Component-InstancePerContext-0.001001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Component-InstancePerContext/
COMMENT=	Return a new instance a component on each request

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Moose>0:../../devel/p5-Moose
DEPENDS+=	p5-Scalar-List-Utils>0:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Component/InstancePerContext/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
