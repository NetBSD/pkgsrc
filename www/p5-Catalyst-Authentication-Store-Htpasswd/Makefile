# $NetBSD: Makefile,v 1.23 2022/06/28 11:37:14 wiz Exp $

DISTNAME=	Catalyst-Authentication-Store-Htpasswd-1.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Authentication-Store-Htpasswd
COMMENT=	Authen::Htpasswd based user storage/authentication
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Authen-Htpasswd>=0.13:../../security/p5-Authen-Htpasswd
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10006:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Crypt-PasswdMD5-[0-9]*:../../security/p5-Crypt-PasswdMD5
DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst-[0-9]*:../../www/p5-Test-WWW-Mechanize-Catalyst

REPLACE_PERL+=	lib/Catalyst/Authentication/Store/*.pm
REPLACE_PERL+=	lib/Catalyst/Authentication/Store/Htpasswd/*.pm

PERL5_PACKLIST=		auto/Catalyst/Authentication/Store/Htpasswd/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
