# $NetBSD: Makefile,v 1.4 2011/08/14 16:06:09 obache Exp $

DISTNAME=	Template-Plugin-Clickable-Email-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Clickable-Email/
COMMENT=	TT2 plugin to transform email addresses in to HTML links
LICENSE=	2-clause-bsd

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Email-Find-[0-9]*:../../mail/p5-Email-Find

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Plugin/Clickable/Email/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
