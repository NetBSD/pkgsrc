# $NetBSD: Makefile,v 1.3 2009/04/30 20:06:37 sno Exp $

DISTNAME=	Catalyst-Component-ACCEPT_CONTEXT-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jrockway/Catalyst-Component-ACCEPT_CONTEXT/
COMMENT=	Make current Catalyst request context available in Models and Views
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

BUILD_DEPENDS+=	p5-Devel-Cycle-[0-9]*:../../devel/p5-Devel-Cycle

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Component/ACCEPT_CONTEXT/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
