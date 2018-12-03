---
 drivers/rtc/nvmem.c | 24 ++++++++++--------------
 include/linux/rtc.h |  1 -
 2 files changed, 10 insertions(+), 15 deletions(-)

diff --git a/drivers/rtc/nvmem.c b/drivers/rtc/nvmem.c
index 2a7220d8b02d..ebdfe8e3a1a0 100644
--- a/drivers/rtc/nvmem.c
+++ b/drivers/rtc/nvmem.c
@@ -25,11 +25,9 @@ rtc_nvram_read(struct file *filp, struct kobject *kobj,
 	       struct bin_attribute *attr,
 	       char *buf, loff_t off, size_t count)
 {
-	struct rtc_device *rtc = attr->private;
-
 	dev_warn_once(kobj_to_dev(kobj), nvram_warning);
 
-	return nvmem_device_read(rtc->nvmem, off, count, buf);
+	return nvmem_device_read(attr->private, off, count, buf);
 }
 
 static ssize_t
@@ -37,14 +35,13 @@ rtc_nvram_write(struct file *filp, struct kobject *kobj,
 		struct bin_attribute *attr,
 		char *buf, loff_t off, size_t count)
 {
-	struct rtc_device *rtc = attr->private;
-
 	dev_warn_once(kobj_to_dev(kobj), nvram_warning);
 
-	return nvmem_device_write(rtc->nvmem, off, count, buf);
+	return nvmem_device_write(attr->private, off, count, buf);
 }
 
-static int rtc_nvram_register(struct rtc_device *rtc, size_t size)
+static int rtc_nvram_register(struct rtc_device *rtc,
+			      struct nvmem_device *nvmem, size_t size)
 {
 	int err;
 
@@ -56,7 +53,7 @@ static int rtc_nvram_register(struct rtc_device *rtc, size_t size)
 
 	rtc->nvram->attr.name = "nvram";
 	rtc->nvram->attr.mode = 0644;
-	rtc->nvram->private = rtc;
+	rtc->nvram->private = nvmem;
 
 	sysfs_bin_attr_init(rtc->nvram);
 
@@ -85,21 +82,20 @@ static void rtc_nvram_unregister(struct rtc_device *rtc)
 int rtc_nvmem_register(struct rtc_device *rtc,
 		       struct nvmem_config *nvmem_config)
 {
-	if (!IS_ERR_OR_NULL(rtc->nvmem))
-		return -EBUSY;
+	struct nvmem_device *nvmem;
 
 	if (!nvmem_config)
 		return -ENODEV;
 
 	nvmem_config->dev = rtc->dev.parent;
 	nvmem_config->owner = rtc->owner;
-	rtc->nvmem = devm_nvmem_register(rtc->dev.parent, nvmem_config);
-	if (IS_ERR(rtc->nvmem))
-		return PTR_ERR(rtc->nvmem);
+	nvmem = devm_nvmem_register(rtc->dev.parent, nvmem_config);
+	if (IS_ERR(nvmem))
+		return PTR_ERR(nvmem);
 
 	/* Register the old ABI */
 	if (rtc->nvram_old_abi)
-		rtc_nvram_register(rtc, nvmem_config->size);
+		rtc_nvram_register(rtc, nvmem, nvmem_config->size);
 
 	return 0;
 }
diff --git a/include/linux/rtc.h b/include/linux/rtc.h
index c8bb4a2b48c3..40ecdb5a369e 100644
--- a/include/linux/rtc.h
+++ b/include/linux/rtc.h
@@ -138,7 +138,6 @@ struct rtc_device {
 
 	bool registered;
 
-	struct nvmem_device *nvmem;
 	/* Old ABI support */
 	bool nvram_old_abi;
 	struct bin_attribute *nvram;
-- 
2.19.1

  