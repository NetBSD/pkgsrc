# $NetBSD: Makefile,v 1.14 2019/08/11 13:24:31 wiz Exp $

DISTNAME=	Catalyst-Plugin-Authorization-ACL-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Plugin-Authorization-ACL
COMMENT=	ACL support for Catalyst applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Plugin-Authentication-[0-9]*:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles-[0-9]*:../../www/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Catalyst-Runtime>=5.80013:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Throwable-[0-9]*:../../devel/p5-Class-Throwable
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Tree-Simple-[0-9]*:../../devel/p5-Tree-Simple
DEPENDS+=	p5-Tree-Simple-VisitorFactory-[0-9]*:../../devel/p5-Tree-Simple-VisitorFactory
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

BUILD_DEPENDS+=	p5-Catalyst-Plugin-Session-[0-9]*:../../www/p5-Catalyst-Plugin-Session
BUILD_DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst-[0-9]*:../../www/p5-Test-WWW-Mechanize-Catalyst

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Catalyst/Plugin/Authorization/ACL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
