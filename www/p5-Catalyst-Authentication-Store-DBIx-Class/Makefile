# $NetBSD: Makefile,v 1.6 2010/03/10 11:10:13 sno Exp $

DISTNAME=	Catalyst-Authentication-Store-DBIx-Class-0.1083
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Authentication-Store-DBIx-Class/
COMMENT=	Storage class for Catalyst Authentication using DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Model-DBIC-Schema>=0.18:../../databases/p5-Catalyst-Model-DBIC-Schema
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10008:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=     	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class

PERL5_PACKLIST= 	auto/Catalyst/Authentication/Store/DBIx/Class/.packlist
PERL5_MODULE_TYPE=	Module::Install
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
