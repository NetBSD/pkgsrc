# $NetBSD: Makefile,v 1.11 2018/08/22 09:47:52 wiz Exp $

DISTNAME=	Task-Catalyst-Tutorial-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Task-Catalyst-Tutorial/
COMMENT=	Tutorial to learn everything about Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Authentication-Store-DBIx-Class>=0.1082:../../www/p5-Catalyst-Authentication-Store-DBIx-Class
DEPENDS+=	p5-Catalyst-Controller-HTML-FormFu>=0.03004:../../www/p5-Catalyst-Controller-HTML-FormFu
DEPENDS+=	p5-Catalyst-Devel>=1.08:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-Catalyst-Manual>=5.7014:../../www/p5-Catalyst-Manual
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10008:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Plugin-Authorization-ACL>=0.10:../../www/p5-Catalyst-Plugin-Authorization-ACL
DEPENDS+=	p5-Catalyst-Plugin-Authorization-Roles>=0.07:../../www/p5-Catalyst-Plugin-Authorization-Roles
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.19:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie>=0.09:../../www/p5-Catalyst-Plugin-Session-State-Cookie
DEPENDS+=	p5-Catalyst-Plugin-Session-Store-FastMmap>=0.05:../../www/p5-Catalyst-Plugin-Session-Store-FastMmap
DEPENDS+=	p5-Catalyst-Plugin-StackTrace>=0.09:../../www/p5-Catalyst-Plugin-StackTrace
DEPENDS+=	p5-Catalyst-Runtime>=5.70150:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-View-TT>=0.27:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-DBIx-Class>=0.08010:../../databases/p5-DBIx-Class

REPLACE_PERL+=	examples/MyApp/script/*.pl
REPLACE_PERL+=	examples/MyApp/t/*.t

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Task/Catalyst/Tutorial/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
