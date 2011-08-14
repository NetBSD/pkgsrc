# $NetBSD: Makefile,v 1.3 2011/08/14 16:05:47 obache Exp $

DISTNAME=	Catalyst-Authentication-Store-Htpasswd-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Authentication-Store-Htpasswd/
COMMENT=	Authen::Htpasswd based user storage/authentication
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Authen-Htpasswd>=0.13:../../security/p5-Authen-Htpasswd
DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10006:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Crypt-PasswdMD5-[0-9]*:../../security/p5-Crypt-PasswdMD5

BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst-[0-9]*:../../www/p5-Test-WWW-Mechanize-Catalyst
BUILD_DEPENDS+=	p5-Test-use-ok-[0-9]*:../../devel/p5-Test-use-ok

REPLACE_PERL+=	lib/Catalyst/Authentication/Store/*.pm
REPLACE_PERL+=	lib/Catalyst/Authentication/Store/Htpasswd/*.pm

PERL5_PACKLIST= 	auto/Catalyst/Authentication/Store/Htpasswd/.packlist
PERL5_MODULE_TYPE=	Module::Install
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
