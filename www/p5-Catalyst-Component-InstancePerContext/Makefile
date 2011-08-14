# $NetBSD: Makefile,v 1.5 2011/08/14 16:05:47 obache Exp $

DISTNAME=	Catalyst-Component-InstancePerContext-0.001001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Component-InstancePerContext/
COMMENT=	Return a new instance a component on each request

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Moose>0:../../devel/p5-Moose
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Component/InstancePerContext/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
