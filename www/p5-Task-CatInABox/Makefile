# $NetBSD: Makefile,v 1.13 2019/08/11 13:25:00 wiz Exp $

DISTNAME=	Task-CatInABox-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Task/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Task-CatInABox
COMMENT=	Catalyst and related modules for exploring Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Authentication-Credential-HTTP-[0-9]*:../../www/p5-Catalyst-Authentication-Credential-HTTP
DEPENDS+=	p5-Catalyst-Authentication-Store-DBIx-Class>=0.1082:../../www/p5-Catalyst-Authentication-Store-DBIx-Class
DEPENDS+=	p5-Catalyst-Authentication-Store-Htpasswd-[0-9]*:../../www/p5-Catalyst-Authentication-Store-Htpasswd
DEPENDS+=	p5-Catalyst-Devel-[0-9]*:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-Catalyst-Model-DBIC-Schema-[0-9]*:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Model-File-[0-9]*:../../www/p5-Catalyst-Model-File
DEPENDS+=	p5-Catalyst-Plugin-Authentication-[0-9]*:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-View-JSON-[0-9]*:../../www/p5-Catalyst-View-JSON
DEPENDS+=	p5-Catalyst-View-TT-[0-9]*:../../www/p5-Catalyst-View-TT
DEPENDS+=	p5-DBIx-Class-[0-9]*:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-EncodedColumn-[0-9]*:../../databases/p5-DBIx-Class-EncodedColumn
DEPENDS+=	p5-DBIx-Class-Schema-Loader-[0-9]*:../../databases/p5-DBIx-Class-Schema-Loader
DEPENDS+=	p5-DBIx-Class-TimeStamp-[0-9]*:../../databases/p5-DBIx-Class-TimeStamp
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Task/CatInABox/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
