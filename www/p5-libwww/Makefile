# $NetBSD: Makefile,v 1.87 2013/12/09 14:17:56 obache Exp $

DISTNAME=	libwww-perl-6.05
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	2
SVR4_PKGNAME=	p5lww
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GA/GAAS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/libwww-perl/
COMMENT=	Perl5 library for WWW access
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.10,p5-Digest-MD5>=0}:../../security/p5-Digest-MD5
#		Encode in perl 5.14
DEPENDS+=	p5-Encode-Locale>=0:../../textproc/p5-Encode-Locale
DEPENDS+=	p5-File-Listing>=6:../../devel/p5-File-Listing
#		HTML::Entities in perl 5.14
#		HTML::HeadParser in perl 5.14
DEPENDS+=	p5-HTTP-Cookies>=6:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Daemon>=6:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Negotiate>=6:../../www/p5-HTTP-Negotiate
#		HTTP::{Request,Request::Common,Response,Status} in HTTP::Message
DEPENDS+=	p5-HTTP-Message>=6:../../www/p5-HTTP-Message
#		IO::Select in perl 5.14
#		IO::Socket in perl 5.14
DEPENDS+=	p5-LWP-MediaTypes>=6:../../www/p5-LWP-MediaTypes
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=2.1}:../../converters/p5-MIME-Base64
DEPENDS+=	{perl>=5.10,p5-Net>=1.09}:../../net/p5-Net # for Net::FTP>=2.58
DEPENDS+=	p5-Net-HTTP>=6:../../www/p5-Net-HTTP
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
#		URI::Escape in URI
DEPENDS+=	p5-WWW-RobotRules>=6.01:../../www/p5-WWW-RobotRules

# Optionals
DEPENDS+=	p5-LWP-Protocol-https>=6.02:../../www/p5-LWP-Protocol-https
DEPENDS+=	{perl>=5.9.4,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/LWP/.packlist
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
