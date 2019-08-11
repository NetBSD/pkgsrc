# $NetBSD: Makefile,v 1.122 2019/08/11 13:25:07 wiz Exp $

DISTNAME=	libwww-perl-6.39
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libwww-perl
COMMENT=	Perl5 library for WWW access
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Encode-Locale>=0:../../textproc/p5-Encode-Locale
DEPENDS+=	p5-File-Listing>=6:../../devel/p5-File-Listing
DEPENDS+=	p5-HTTP-Cookies>=6:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Daemon>=6:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Negotiate>=6:../../www/p5-HTTP-Negotiate
DEPENDS+=	p5-HTTP-Message>=6:../../www/p5-HTTP-Message
DEPENDS+=	p5-LWP-MediaTypes>=6:../../www/p5-LWP-MediaTypes
#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=2.1}:../../converters/p5-MIME-Base64
#DEPENDS+=	{perl>=5.10,p5-Net>=1.09}:../../net/p5-Net # for Net::FTP>=2.58
DEPENDS+=	p5-Net-HTTP>=6.18:../../www/p5-Net-HTTP
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+=	p5-WWW-RobotRules>=6.01:../../www/p5-WWW-RobotRules

# Optionals
DEPENDS+=	p5-LWP-Protocol-https>=6.02:../../www/p5-LWP-Protocol-https
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
BUILD_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/libwww/perl/.packlist
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
