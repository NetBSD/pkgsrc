# $NetBSD: Makefile,v 1.4 2009/06/30 00:07:24 joerg Exp $

DISTNAME=	Catalyst-Plugin-Authorization-Roles-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authorization-Roles/
COMMENT=	Role based authorization for Catalyst

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10003:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Set-Object>=1.14:../../devel/p5-Set-Object
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
DEPENDS+=	p5-UNIVERSAL-isa>=0.05:../../devel/p5-UNIVERSAL-isa

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Authorization/Roles/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
