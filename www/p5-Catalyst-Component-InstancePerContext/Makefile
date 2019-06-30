# $NetBSD: Makefile,v 1.17 2019/06/30 20:17:24 nia Exp $

DISTNAME=	Catalyst-Component-InstancePerContext-0.001001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Component-InstancePerContext
COMMENT=	Return a new instance a component on each request

DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-URI-ws>=0.03:../../www/p5-URI-ws
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Component/InstancePerContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
