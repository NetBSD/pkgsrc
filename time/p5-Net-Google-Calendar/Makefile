# $NetBSD: Makefile,v 1.8 2013/12/09 14:17:54 obache Exp $

DISTNAME=		Net-Google-Calendar-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		time net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Google-Calendar/
COMMENT=		Perl module for accessing Google calendars
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-XML-Atom-[0-9]*:../../textproc/p5-XML-Atom
DEPENDS+=		p5-Net-Google-AuthSub-[0-9]*:../../net/p5-Net-Google-AuthSub
BUILD_DEPENDS+=         {perl>=5.17.1,p5-Module-Build>=0.40000}:../../devel/p5-Module-Build

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Net/Google/Calendar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
