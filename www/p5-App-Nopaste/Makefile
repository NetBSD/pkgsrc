# $NetBSD: Makefile,v 1.14 2011/08/14 16:05:43 obache Exp $

DISTNAME=	App-Nopaste-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-Nopaste/
COMMENT=	Perl 5 module providing easy access to any pastebin
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/App/Nopaste/.packlist

REPLACE_PERL+=	bin/nopaste

DEPENDS+=	p5-Moose>=0.74:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Getopt>=0.17:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize

# Recommended dependencies
DEPENDS+=	p5-Clipboard-[0-9]*:../../x11/p5-Clipboard
DEPENDS+=	p5-Config-INI-[0-9]*:../../devel/p5-Config-INI
DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create-[0-9]*:../../www/p5-WWW-Pastebin-PastebinCom-Create
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
