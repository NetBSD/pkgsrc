# $NetBSD: Makefile,v 1.3 2009/04/24 08:22:21 sno Exp $

DISTNAME=	App-Nopaste-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-Nopaste/
COMMENT=	Perl 5 module providing easy access to any pastebin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/App/Nopaste/.packlist

# We drop the git module dependency as we require p5-Config-INI
MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

DEPENDS+=	p5-Clipboard-[0-9]*:../../x11/p5-Clipboard
DEPENDS+=	p5-Config-INI-[0-9]*:../../devel/p5-Config-INI
DEPENDS+=	{perl>=5.10,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=0.50:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Getopt>=0.13:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-WWW-Pastebin-PastebinCom-Create-[0-9]*:../../www/p5-WWW-Pastebin-PastebinCom-Create
DEPENDS+=	p5-WWW-Pastebin-RafbNet-Create-[0-9]*:../../www/p5-WWW-Pastebin-RafbNet-Create

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
