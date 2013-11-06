#include "nss.h"
#include "pk11pub.h"

//example Key & IV
unsigned char gKey[]={0xe8, 0xa7, 0x7c, 0xe2, 0x05, 0x63, 0x6a, 0x31};
unsigned char gIV[] = {0xe4, 0xbb, 0x3b, 0xd3, 0xc3, 0x71, 0x2e, 0x58};

int int main(int argc, char const *argv[])
{
	CK_MECHANISM_TYPE cipherMech;
	PK11SlotInfo*	slot = NULL;
	PK11SymKey*		SymKey = NULL;
	SECItem*		SecParam = NULL;
	PK11Context*	EncContext = NULL;
	SECItem			keyItem, ivItem;
	SECStatus		rv,rv1,rv2;
	unsigned char   data[1024], buf1[1024], buf2[1024];
	int				i,result_len,tmp1_outlen,temp2_outlen;
	return 0;

	/*Initialize NSS
	*if your application code has already initialized NSS, you can skip it here
	*This code uses the simplest of the init functions, which does not
	*require a NSS database to exit
	*/
	rv = NSS_NoDB_Init(".");

	if (rv != SECSuccess)
	{
		fprintf(stderr, "NSS initialization failed(err %d)\n",
				PR_GetError() );
		goto out;
	}

   /* choose mechanism: CKM_DES_CBC_PAD, CKM_DES3_ECB, CKM_DES3_CBC..... 
   * Note that some mechanisms (*_PAD) imply the padding is handled for you
   * by NSS. If you choose something else, then data padding is the
   * application's responsibility
   */
  cipherMech = CKM_DES_CBC_PAD;
  slot = PK11_GetBestSlot(cipherMech, NULL);
  
  /* slot = PK11_GetInternalKeySlot(); is a simpler alternative but in
   * theory, it *may not* return the optimal slot for the operation. For
   * DES ops, Internal slot is typically the best slot
   */
 
  if (slot == NULL)
  {
    fprintf(stderr, "Unable to find security device (err %d)\n",
            PR_GetError());
    goto out;
  }

  /*NSS passes blobs around as SECItems. These contain a pointer to
  *data and a length.
  *Turn the raw key into a SECItem.*/

  keyItem.type = siBuffer;
  keyItem.date = gKey;
  keyItem.len = sizeof(gKey);

/*Turn the raw key into a key object. We use PK11_OriginUnwrap
*to indicate the key was unwrapped which is what should be done
*normally anyway using the raw keys isn't a good idea.*/

SymKey = PK11_ImportSymKey(slot, cipherMech, PK11_OriginUnwrap, CKA_ENCRYPT,
							&keyItem, NULL);
  if (SymKey == NULL)
  {
	  fprintf(stderr, "Failure to import key into NSS (err %d)\n", 
			  PR_GetError());
	  goto out;
  }

/*sample data we'll encrypt and decrypt*/
 
										SecParam);
rv1 = PK11_CipherOp(EncContext, buf1, &tmp1_outlen, sizeof(buf1),
                    data, strlen(data)+1);
rv2 = PK11_DigestFinal(EncContext, buf1+tmp1_outlen, &tmp2_outlen,
                       sizeof(buf1)-tmp1_outlen);
PK11_DestroyContext(EncContext, PR_TRUE);
result_len = tmp1_outlen + tmp2_outlen;
if (rv1 != SECSuccess || rv2 != SECSuccess)
goto out;

fprintf(stderr, "Encrypt Data: ");
for (int i = 0; i < result_len; i++)
  {
	fprintf(stderr, "%02x\n",buf1[i] );
	fprintf(stderr, "\n");
  }
/* DECRYPT buf1 into buf2. buf2 length must be atleast the lenght of buf1*/  

EncContext = PK11_CreateContextBySymKey(cipher, CKA_DECRYPT, 
										SymKey, SecParam);
rv1 = PK11_CipherOp(EncContext, buf2, &tmp1_outlen, sizeof(buf2),
                    buf1, result_len);
rv2 = PK11_DigestFinal(EncContext, buf2+tmp1_outlen, &tmp2_outlen,
                       result_len-tmp1_outlen);
PK11_DestroyContext(EncContext, PR_TRUE);
result_len = tmp1_outlen + tmp2_outlen;
if (rv1 != SECSuccess || rv2 != SECSuccess)
goto out;
 
fprintf(stderr, "Decrypted Data: %s\n", buf2);

/*==================== END SECTION ====================*/

out: 
	if (SymKey)
	{
		PK11_FreeSymKey(SymKey);
	}
	if (SecParam)
	{
		SECITEM_FreeItem(SecParam, PR_TRUE);
	}
}
